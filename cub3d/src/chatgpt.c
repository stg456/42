#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_DIMENSION 100

typedef struct {
    char direction[3];
    char path[MAX_DIMENSION];
} Texture;

typedef struct {
    int r;
    int g;
    int b;
} Color;

int is_valid_texture(Texture* textures, int num_textures) {
    if (num_textures != 4) {
        printf("Erreur : Le nombre de textures doit être exactement 4.\n");
        return 0;
    }

    // Vérification supplémentaire des textures si nécessaire

    return 1;
}

int is_valid_color(Color floor_color, Color ceiling_color) {
    // Vérification de la validité des couleurs si nécessaire

    return 1;
}

int is_valid_map(char** map, int rows, int cols, int* start_row, int* start_col) {
    // Vérification de la validité de la carte si nécessaire

    return 1;
}

void parse_file(const char* filename) {
    int file = open(filename, O_RDONLY);
    if (file == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(1);
    }

    Texture textures[4];
    Color floor_color, ceiling_color;
    char** map = NULL;
    int rows = 0, cols = 0;
    int start_row = -1, start_col = -1;
    int num_textures = 0;
    int num_colors = 0;
    int num_map_rows = 0;
    int map_allocated = 0;

    char line[MAX_DIMENSION];
    char buffer;
    int bytes_read;
    int i = 0, j = 0;
    int line_start = 1;

    while ((bytes_read = read(file, &buffer, 1)) > 0) {
        if (buffer == '\n') {
            line[i] = '\0';
            i = 0;
            line_start = 1;

            if (line[0] == '\0') {
                // Ignorer les lignes vides
                continue;
            }

            if (line[0] == 'N' && line[1] == 'O') {
                if (num_textures >= 4) {
                    printf("Erreur : Trop de textures spécifiées.\n");
                    close(file);
                    exit(1);
                }

                strncpy(textures[num_textures].direction, line, 3);
                strncpy(textures[num_textures].path, line + 3, sizeof(textures[num_textures].path) - 1);
                num_textures++;
            }
            else if (line[0] == 'F') {
                if (num_colors >= 2) {
                    printf("Erreur : Trop de couleurs spécifiées.\n");
                    close(file);
                    exit(1);
                }

                char* color_value = strchr(line, ' ');
                char* comma1 = strchr(color_value, ',');
                char* comma2 = strchr(comma1 + 1, ',');

                char r_str[4];
                char g_str[4];
                char b_str[4];

                strncpy(r_str, color_value + 1, comma1 - color_value - 1);
                strncpy(g_str, comma1 + 1, comma2 - comma1 - 1);
                strncpy(b_str, comma2 + 1, strlen(comma2 + 1));

                r_str[comma1 - color_value - 1] = '\0';
                g_str[comma2 - comma1 - 1] = '\0';
                b_str[strlen(comma2 + 1)] = '\0';

                floor_color.r = atoi(r_str);
                floor_color.g = atoi(g_str);
                floor_color.b = atoi(b_str);

                num_colors++;
            }
            else if (line[0] == 'C') {
                if (num_colors >= 2) {
                    printf("Erreur : Trop de couleurs spécifiées.\n");
                    close(file);
                    exit(1);
                }

                char* color_value = strchr(line, ' ');
                char* comma1 = strchr(color_value, ',');
                char* comma2 = strchr(comma1 + 1, ',');

                char r_str[4];
                char g_str[4];
                char b_str[4];

                strncpy(r_str, color_value + 1, comma1 - color_value - 1);
                strncpy(g_str, comma1 + 1, comma2 - comma1 - 1);
                strncpy(b_str, comma2 + 1, strlen(comma2 + 1));

                r_str[comma1 - color_value - 1] = '\0';
                g_str[comma2 - comma1 - 1] = '\0';
                b_str[strlen(comma2 + 1)] = '\0';

                ceiling_color.r = atoi(r_str);
                ceiling_color.g = atoi(g_str);
                ceiling_color.b = atoi(b_str);

                num_colors++;
            }
        }
        else {
            line[i] = buffer;
            i++;
            if (line_start) {
                if (buffer == ' ') {
                    line_start = 0;
                }
                else {
                    printf("Erreur : Caractère non valide dans le fichier.\n");
                    close(file);
                    exit(1);
                }
            }
        }
    }

    if (bytes_read == -1) {
        perror("Erreur lors de la lecture du fichier");
        close(file);
        exit(1);
    }

    // Vérification de la validité des données

    if (!is_valid_texture(textures, num_textures)) {
        close(file);
        exit(1);
    }

    if (!is_valid_color(floor_color, ceiling_color)) {
        close(file);
        exit(1);
    }

    // Suite du traitement du fichier...

    close(file);
}
