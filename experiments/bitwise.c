#include <stdio.h>

int get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int main(void)
{
	int rrr = 128;
	int g = 2;
	int nbr = 2147483647;
	int trgb = 12344523;
	int r = 0;

	r = get_r(trgb);
	r = create_trgb(0, r, 0, 0);

	printf("%d\n", r);
	printf("t = %d\n r = %d\n", get_t(trgb), get_r(trgb));
	printf("%d\n", r >> 7);
	printf("%d\n", nbr >> 30);
	printf("%d\n", 0xff << 24);
	printf("%d\n", 0xff << 4);

	return (0);
}
