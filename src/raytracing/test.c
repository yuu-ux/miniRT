#include <stdio.h>
#include <scene.h>

// === Print out test results ===
void print_vec(const char *label, t_vec v)
{
	printf("%s: (%.2f, %.2f, %.2f)\n", label, v.x, v.y, v.z);
}

int main(void)
{
	t_vec v1 = {3, 4, 0};
	t_vec v2 = {1, 0, 2};

	t_vec v_sub = subtract(v1, v2);
	t_vec v_add = add(v1, v2);
	t_vec v_scaled = scale(v1, 0.5);
	t_vec v_norm = normalize(v1);
	double v1_len = length(v1);
	double dot = dot_product(v1, v2);
	t_vec cross = cross_product(v1, v2);

	// Output
	print_vec("v1", v1);
	print_vec("v2", v2);
	print_vec("v1 - v2", v_sub);
	print_vec("v1 + v2", v_add);
	print_vec("v1 * 0.5", v_scaled);
	printf("length of v1: %.2f\n", v1_len);
	print_vec("normalize(v1)", v_norm);
	printf("dot_product(v1, v2): %.2f\n", dot);
	print_vec("cross_product(v1, v2)", cross);

	return 0;
}
/* Expected Output:
v1: (3.00, 4.00, 0.00)
v2: (1.00, 0.00, 2.00)
v1 - v2: (2.00, 4.00, -2.00)
v1 + v2: (4.00, 4.00, 2.00)
v1 * 0.5: (1.50, 2.00, 0.00)
length of v1: 5.00
normalize(v1): (0.60, 0.80, 0.00)
dot_product(v1, v2): 3.00
cross_product(v1, v2): (8.00, -6.00, -4.00)
*/