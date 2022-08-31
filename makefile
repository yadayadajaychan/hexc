# ----------------------------
# Makefile Options
# ----------------------------

NAME = hexc
DESCRIPTION = "Calculator for Computer Scientists"
COMPRESSED = NO
ARCHIVED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz
HAS_PRINTF := NO

# ----------------------------

include $(shell cedev-config --makefile)
