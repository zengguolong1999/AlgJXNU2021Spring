// This program tests warning -Wimplicit-fallthrough in GCC.
int main() {
    int cond = 2;
    int val;
    switch(cond) {
        case 1:
            val = 1;
            break;
        case 2:
            val = 2;
            //return -1;
        case 3:
            val = 3;
            //break;
    }
    return -1;
}
