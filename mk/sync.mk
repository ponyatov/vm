.PHONY: sync
sync:
	unison cross
	unison $(APP)
	git add doc
