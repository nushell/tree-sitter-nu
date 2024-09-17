package tree_sitter_nu_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_nu "github.com/tree-sitter/tree-sitter-nu/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_nu.Language())
	if language == nil {
		t.Errorf("Error loading Nu grammar")
	}
}
