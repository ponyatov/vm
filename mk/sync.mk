.PHONY: sync
sync:
	unison cross
	unison u
	unison $(APP)
	git add doc
