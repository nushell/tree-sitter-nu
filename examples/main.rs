extern crate tree_sitter_nu;
use tree_sitter::{Language, Parser};

fn main() {
    let src = include_str!("..\\example-file.nu");
    let nu_lang: Language = tree_sitter_nu::language();
    let mut parser = Parser::new();
    parser.set_language(nu_lang).unwrap();
    let parse_tree = parser.parse(&src, None).unwrap();
    println!("{}", parse_tree.root_node().to_sexp());

    // let query = Query::new(
    //     nu_lang,
    //     r#"
    //     ((custom_command
    //       custom_command_name: (identifier)
    //     ))
    //     "#
    // ).unwrap();

    // let mut query_cursor = QueryCursor::new();
    // let all_matches = query_cursor.matches(&query, parse_tree.root_node(), src.as_bytes());
    // println!("matches: {:?}", all_matches.count());
}
