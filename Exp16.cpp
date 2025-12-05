#include <stdio.h>
#include <string.h>
typedef struct {
    int id;
    char name[20];
} Emp;
int main() {
    FILE *f = fopen("emp.dat", "wb+");
    if (!f) { perror("fopen"); return 1; }
    Emp e;
    // write two records
    e.id = 1; strcpy(e.name, "Alice"); fwrite(&e, sizeof(e), 1, f);
    e.id = 2; strcpy(e.name, "Bob");   fwrite(&e, sizeof(e), 1, f);
    // read second record randomly
    fseek(f, sizeof(e) * 1, SEEK_SET); // record index 1 (0-based)
    Emp r; fread(&r, sizeof(r), 1, f);
    printf("Rec2: ID=%d Name=%s\n", r.id, r.name);

    fclose(f);
    return 0;
}
