#include "main.h"

int main(int argc, char *argv[])
{
  // Check for valid arguments
  if (argc < 2) {
    fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
    return 1;
  }

  // Process each filename
  for (int i = 1; i < argc; ++i) {
    char *filename = argv[i];

    // Get PATH environment variable
    char *path = getenv("PATH");
    if (!path) {
      fprintf(stderr, "Error: PATH environment variable not found\n");
      return 1;
    }

    // Loop through each path segment
    char *token, *saveptr;
    while ((token = strtok_r(path, ":", &saveptr)) != NULL) {
      char full_path[MAX_LENGTH];

      // Construct full path
      snprintf(full_path, sizeof(full_path), "%s/%s", token, filename);

      // Check if file exists and is executable
      if (access(full_path, F_OK | X_OK) == 0) {
        printf("%s\n", full_path);
        break; // Found, stop searching
      } else if (errno != ENOENT) { // Ignore "No such file or directory" errors
        fprintf(stderr, "Error: %s: %s\n", full_path, strerror(errno));
      }

      path = NULL; // Reset strtok_r for next iteration
    }

    // File not found in PATH
    if (!strtok_r(path, ":", &saveptr)) {
      printf("%s not found in path\n", filename);
    }
  }

  return 0;
}
