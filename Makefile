# Auto-detect OS
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	OS = linux
endif

ifeq ($(UNAME_S),Darwin)
	OS = mac
endif

ifeq ($(OS),)
	ifneq (,$(findstring Microsoft,$(shell uname -r)))
	OS = wsl
	endif
endif

# Default DISPLAY settings per OS
ifeq ($(OS),linux)
	DISPLAY_CMD = export DISPLAY=$(DISPLAY)
	XHOST_CMD = xhost +local:docker
endif

ifeq ($(OS),mac)
	DISPLAY_CMD = export DISPLAY=host.docker.internal:0
	XHOST_CMD = :
endif

ifeq ($(OS),wsl)
	DISPLAY_CMD = export DISPLAY=host.docker.internal:0
	XHOST_CMD = :
endif

# Targets
.PHONY: build run stop clean osinfo all

all: build
	$(MAKE) run

osinfo:
	@echo "Detected OS: $(OS)"

build:
	$(DISPLAY_CMD)
	docker compose build

run:
	$(DISPLAY_CMD)
	$(XHOST_CMD)
	docker compose up

stop:
	docker compose down

clean:
	docker compose down --rmi all --volumes --remove-orphans
