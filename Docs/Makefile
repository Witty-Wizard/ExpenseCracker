# Minimal makefile for Sphinx documentation

# You can set these variables from the command line, and also
# from the environment for the first two.

ifeq ($(OS),Windows_NT)
	SPHINXOPTS       ?=
	SPHINXBUILD      ?= .venv\Scripts\sphinx-build
	SPHINXAUTOBUILD  ?= .venv\Scripts\sphinx-autobuild
	PIP              ?= .venv\Scripts\pip
	PYTHON           ?= .venv\Scripts\python
	SOURCEDIR        = source
	BUILDDIR         = build

else
	SPHINXOPTS       ?=
	SPHINXBUILD      ?= .venv/bin/sphinx-build
	SPHINXAUTOBUILD  ?= .venv/bin/sphinx-autobuild
	PIP              ?= .venv/bin/pip
	PYTHON           ?= .venv/bin/python
	SOURCEDIR        = source
	BUILDDIR         = build
endif

# Put it first so that "make" without argument is like "make help".
help:
	@$(SPHINXBUILD) -M help "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)

.PHONY: help Makefile setup dev

# Setup virtual environment and install dependencies
setup:
	python -m venv .venv 
	$(PYTHON) -m pip install --upgrade pip 
	$(PIP) install -r requirements.txt

# Run sphinx-autobuild for live-reloading docs during development
dev:
	@$(SPHINXAUTOBUILD) "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS)

# Catch-all target: route all unknown targets to Sphinx using the new
# "make mode" option.  $(O) is meant as a shortcut for $(SPHINXOPTS).
%: Makefile
	@$(SPHINXBUILD) -M $@ "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)
