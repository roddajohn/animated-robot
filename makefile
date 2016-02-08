default: project_1.c
	rm image.ppm
	rm image.jpg
	gcc -o output project_1.c

output: project_1.c
	gcc -o output project_1.c

run:
	./output
	convert image.ppm image.jpg
	open image.jpg
