#include <stdio.h>
#include <stdlib.h>


void readcsv(float* data, char* filename, size_t length){
	FILE *f_data = fopen(filename, "ra");
	if ( f_data == NULL ) {
		printf("File not found: %s\n", filename);
		exit(1);
	}

	for ( int i = 0; i < length; i = i + 2 ) fscanf(f_data, "%f,%f\n", &(data[i]), &(data[i+1]));

	fclose(f_data);
}

void writebin(float* data, char* filename, size_t length) {
	FILE* f_data = fopen(filename, "wb");

	fwrite(data, sizeof(float), length, f_data);

	fclose(f_data);
}

void readbin(float* data, char* filename, size_t length) {
	FILE* f_data = fopen(filename, "rb");
	if ( f_data == NULL ) {
		printf("File not found: %s\n", filename);
		exit(1);
	}

	fread(data, sizeof(float), length, f_data);

	fclose(f_data);
}


int main(int argc, char **argv) {
	size_t numData = 44691;
	size_t dimension = 2;

	float* data = (float*)malloc(sizeof(float)*numData*dimension);
	float* test = (float*)malloc(sizeof(float)*numData*dimension);

	printf( "Read CSV File Start!\n" );
	readcsv(&data[0], argv[1], numData*dimension);
	printf( "Read CSV File Done!\n" );
	printf( "%f, %f\n", data[0], data[1] );
	printf( "\n" );

	printf( "Write Binary File Start!\n" );
	writebin(&data[0], argv[2], numData*dimension);
	printf( "Write Binary File Done!\n" );
	printf( "\n" );

	printf( "Read Binary File Start!\n" );
	readbin(&test[0], argv[2], numData*dimension);
	printf( "Read Binary File Done!\n" );
	printf( "%f, %f\n", test[0], test[1] );

	return 0;
}
