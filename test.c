#include <unistd.h>


void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	basecamp(void)
{
	int i = 1;

	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "basecamp", 8);
		else if (i % 3 == 0)
			write(1, "base", 4);
		else if (i % 5 == 0)
			write(1, "camp", 4);
		else
			ft_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
}

int main(void)
{
	basecamp();
}