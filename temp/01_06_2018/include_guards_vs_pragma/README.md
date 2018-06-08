
# Advantages and disadvantages of Include guards and #pragma

Both Include guards and #pragma prevents multiple inclusion of header files, hence preventing multiple defintion errors

- But for Include Guards we might end up creating include guards with same name for two different header files, that will pervent us from including the definitions we actually want.

- #pragma once files are excluded based on their filesystem-level identity, this can't protect against including a header twice if it exists in more than one location in a project.
