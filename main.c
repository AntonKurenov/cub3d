#include "mlx/mlx.h"

int main(void)
{
	void *mlx_ptr;
	void *mlx_win;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "HELLo WOrld");
	mlx_loop(mlx_ptr);
}
