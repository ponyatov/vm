.PHONY: ai
ai: sync doc
	cat doc/cross/*.md doc/$(APP)/*.md README.md > tmp/ai.$(APP).md
