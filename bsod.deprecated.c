#include "kernel/bsod.h"
#include "utils/utils.h"
#include "types/define.h"
#include "types/types.h"

DWORD vga_index;
static DWORD next_line_index = 1;
UCHAR g_fore_color = WHITE, g_back_color = BLUE;
int digit_ascii_codes[10] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};

KERNEL
USHORT vga_entry(IN UCHAR ch,
				 IN UCHAR fore_color,
				 IN UCHAR back_color)
{
  USHORT ax = 0;
  UCHAR ah = 0, al = 0;

  ah = back_color;
  ah <<= 4;
  ah |= fore_color;
  ax = ah;
  ax <<= 8;
  al = ch;
  ax |= al;

  return ax;
}

KERNEL
VOID clear_vga_buffer(IN USHORT **buffer,
					  IN UCHAR fore_color,
					  IN UCHAR back_color)
{
  UINT i;
  for(i = 0; i < BUFSIZE; i++){
    (*buffer)[i] = vga_entry(NULL, fore_color, back_color);
  }
  next_line_index = 1;
  vga_index = 0;
}

KERNEL
VOID init_vga(IN UCHAR fore_color,
		 	  IN UCHAR back_color)
{  
  vga_buffer = (USHORT*)VGA_ADDRESS;
  clear_vga_buffer(&vga_buffer, fore_color, back_color);
  g_fore_color = fore_color;
  g_back_color = back_color;
}

KERNEL
VOID print_new_line()
{
  if(next_line_index >= 55){
    next_line_index = 0;
    clear_vga_buffer(&vga_buffer, g_fore_color, g_back_color);
  }
  vga_index = 80*next_line_index;
  next_line_index++;
}

KERNEL
VOID print_char(IN CHAR ch)
{
  vga_buffer[vga_index] = vga_entry(ch, g_fore_color, g_back_color);
  vga_index++;
}

KERNEL
VOID print_string(IN CHAR *str)
{
  UINT index = 0;
  while(str[index]){
    print_char(str[index]);
    index++;
  }
}

KERNEL
VOID print_color_string(IN CHAR *str,
						IN UCHAR fore_color,
						IN UCHAR back_color)
{
  UINT index = 0;
  UCHAR fc, bc;

  fc = g_fore_color;
  bc = g_back_color;
  g_fore_color = fore_color;
  g_back_color = back_color;

  while(str[index]){
    print_char(str[index]);
    index++;
  }

  g_fore_color = fc;
  g_back_color = bc;
}

KERNEL
VOID print_int(IN INT num)
{
  char str_num[digit_count(num)+1];
  itoa(num, str_num);
  print_string(str_num);
}

KERNEL
USHORT get_box_draw_char(IN UCHAR chn,
						 IN UCHAR fore_color,
						 IN UCHAR back_color)
{
  USHORT ax = 0;
  UCHAR ah = 0;

  ah = back_color;
  ah <<= 4;
  ah |= fore_color;
  ax = ah;
  ax <<= 8;
  ax |= chn;

  return ax;
}

VOID gotoxy(IN USHORT x, IN USHORT y)
{
  vga_index = 80*y;
  vga_index += x;
}

KERNEL
VOID draw_generic_box(IN USHORT x,
					  IN USHORT y,
					  IN USHORT width,
					  IN USHORT height,
            IN UCHAR fore_color,
					  IN UCHAR back_color,
					  IN UCHAR topleft_ch,
					  IN UCHAR topbottom_ch,
					  IN UCHAR topright_ch,
					  IN UCHAR leftrightside_ch,
					  IN UCHAR bottomleft_ch,
					  IN UCHAR bottomright_ch)
{
  UINT i;

  //increase vga_index to x & y location
  vga_index = 80*y;
  vga_index += x;

  //draw top-left box character
  vga_buffer[vga_index] = get_box_draw_char(topleft_ch, fore_color, back_color);

  vga_index++;
  //draw box top characters, -
  for(i = 0; i < width; i++){
    vga_buffer[vga_index] = get_box_draw_char(topbottom_ch, fore_color, back_color);
    vga_index++;
  }

  //draw top-right box character
  vga_buffer[vga_index] = get_box_draw_char(topright_ch, fore_color, back_color);

  // increase y, for drawing next line
  y++;
  // goto next line
  vga_index = 80*y;
  vga_index += x;

  //draw left and right sides of box
  for(i = 0; i < height; i++){
    //draw left side character
    vga_buffer[vga_index] = get_box_draw_char(leftrightside_ch, fore_color, back_color);
    vga_index++;
    //increase vga_index to the width of box
    vga_index += width;
    //draw right side character
    vga_buffer[vga_index] = get_box_draw_char(leftrightside_ch, fore_color, back_color);
    //goto next line
    y++;
    vga_index = 80*y;
    vga_index += x;
  }
  //draw bottom-left box character
  vga_buffer[vga_index] = get_box_draw_char(bottomleft_ch, fore_color, back_color);
  vga_index++;
  //draw box bottom characters, -
  for(i = 0; i < width; i++){
    vga_buffer[vga_index] = get_box_draw_char(topbottom_ch, fore_color, back_color);
    vga_index++;
  }
  //draw bottom-right box character
  vga_buffer[vga_index] = get_box_draw_char(bottomright_ch, fore_color, back_color);

  vga_index = 0;
}

KERNEL
VOID draw_box(IN UCHAR boxtype,
              IN USHORT x,
			        IN USHORT y,
              IN USHORT width,
			        IN USHORT height,
              IN UCHAR fore_color,
			        IN UCHAR back_color)
{
  switch(boxtype){
    case BOX_SINGLELINE : 
      draw_generic_box(x, y, width, height, 
                      fore_color, back_color, 
                      218, 196, 191, 179, 192, 217);
      break;

    case BOX_DOUBLELINE : 
      draw_generic_box(x, y, width, height, 
                      fore_color, back_color, 
                      201, 205, 187, 186, 200, 188);
      break;
  }
}

KERNEL
VOID fill_box(IN UCHAR ch,
			  IN USHORT x,
			  IN USHORT y,
			  IN USHORT width,
			  IN USHORT height,
			  IN UCHAR color)
{
  UINT i,j;

  for(i = 0; i < height; i++){
    //increase vga_index to x & y location
    vga_index = 80*y;
    vga_index += x;

    for(j = 0; j < width; j++){
      vga_buffer[vga_index] = get_box_draw_char(ch, 0, color);
      vga_index++;
    }
    y++;
  }
}

KERNEL
VOID kernel_entry()
{
  const char*str = "Box Demo";

  init_vga(WHITE, BLACK);

  gotoxy((VGA_MAX_WIDTH/2)-strlen(str), 1);
  print_color_string("Box Demo", WHITE, BLACK);
  
  draw_box(BOX_DOUBLELINE, 0, 0, BOX_MAX_WIDTH, BOX_MAX_HEIGHT, BRIGHT_GREEN, BLACK);

  draw_box(BOX_SINGLELINE, 5, 3, 20, 5, YELLOW, BLACK);
  gotoxy(10, 6);
  print_color_string("AbrilOS Entry", BRIGHT_RED, WHITE);

  // NULL for only to fill colors, or provide any other character
  fill_box(NULL, 36, 5, 30, 10, RED);

  fill_box(1, 6, 16, 30, 4, GREEN);
  draw_box(BOX_DOUBLELINE, 6, 16, 28, 3, BLUE, GREEN);

}
