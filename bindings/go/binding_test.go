package tree_sitter_nu_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-nu"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_nu.Language())
	if language == nil {
		t.Errorf("Error loading Nu grammar")
	}
}
