#include <string.h>
#include "person.h"

int main(int argc, char* argv[]) {
	srand(time(NULL));
    printf("%d\n", strlen(argv[1]));
	Person p1("Tihamer", "Kiss", argv[1]);
	Person p2("Janos", "Toth");

    /*
	p2.setContact(p1);
	Person p3(p2);
	p3.setFirstName("Anna");
	p3.setLastName("Varga");
    */

    /*
	p1.print();
	p2.print();
	p3.print();
    */

    /*
	printf("Tax id 321 not valid\n");
	p2.setTaxId("321");
	p2.print();
    */

    /*
	printf("Tax id 987654321 valid\n");
	p2.setTaxId("987654321");
	p2.print();
    */

	return 0;
}
