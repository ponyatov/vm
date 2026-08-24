APP = $(notdir $(CURDIR))

.PHONY: sync
sync:
	unison $(APP)
