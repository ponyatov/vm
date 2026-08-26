.PHONY: ai
ai: sync
	cat doc/cross/*.md doc/$(APP)/*.md README.md > tmp/$(APP).ai.md
	tree lib/vm >> tmp/$(APP).ai.md
	find lib/vm -type f -regex '.+..pp' -exec cat {} >> tmp/$(APP).ai.md \;
