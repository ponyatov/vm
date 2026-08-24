.PHONY: sync
sync:
	unison cross
	unison $(APP)
