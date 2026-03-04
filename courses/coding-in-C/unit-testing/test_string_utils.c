#include <assert.h>
#include "string_utils.h"

int main(){
    char val[] = "Hallo";
    char *p = val;
    assert(custom_len(p) == 5);
    assert(custom_len("") == 0);
    assert (custom_len(val) == 5);
}