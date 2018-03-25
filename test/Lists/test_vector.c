#include <stdio.h>
#include "../minunit.h"
#include "../../src/Lists/vector.h"
#include <string.h>

int tests_run = 0;

static char * test_append(){
	vector* v = vector_new();

	vector_append(v, "zero");
	vector_append(v, "one");
	vector_append(v, "two");

	mu_assert("vector_get(0) is not 'zero'", strcmp((char*) vector_get(v, 0), "zero") == 0);
	mu_assert("vector_get(1) is not 'one'", strcmp((char*) vector_get(v, 1), "one") == 0);
	mu_assert("vector_get(2) is not 'two'", strcmp((char*) vector_get(v, 2), "two") == 0);

	return 0;
}

static char * all_tests() {
    mu_run_test(test_append);
    return 0;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}