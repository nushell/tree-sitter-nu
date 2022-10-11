extern crate tree_sitter_nu;
use tree_sitter::{Language, Parser, TreeCursor};

fn main() {
    let src = include_str!("../example-file.nu");
    let nu_lang: Language = tree_sitter_nu::language();
    let mut parser = Parser::new();
    parser.set_language(nu_lang).unwrap();
    let parse_tree = parser.parse(&src, None).unwrap();
    println!("\nTree Walk 1");
    print_tree(&parse_tree);
    println!("\nTree Walk 2");
    let mut tree_cursor = parse_tree.walk();
    walk_tree(&mut tree_cursor, src);
    println!("\n{}", parse_tree.root_node().to_sexp());

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

pub fn print_tree(tree: &tree_sitter::Tree) {
    let mut cursor = tree.walk();
    print_cursor(&mut cursor, 0);
}

fn print_cursor(cursor: &mut TreeCursor, depth: usize) {
    loop {
        let node = cursor.node();
        println!("{}{:#?}", "  ".repeat(depth), node);

        if cursor.goto_first_child() {
            print_cursor(cursor, depth + 1);
            cursor.goto_parent();
        }

        if !cursor.goto_next_sibling() {
            break;
        }
    }
}

fn walk_tree(cursor: &mut TreeCursor, source: &str) {
    // let node = cursor.node();
    // let start_pos = node.start_position();
    // let end_pos = node.end_position();
    // let kind = node.kind().trim();
    // let field_id = cursor.field_id().unwrap_or(0);
    // let field_name = cursor.field_name().unwrap_or("");
    // let node_string = node.utf8_text(source.as_bytes()).unwrap();
    // println!(
    //     "id: [{}], name: [{}], kind: [{}], start_pos: [{} {}] end_pos: [{} {}], node_text: [{}]",
    //     field_id,
    //     field_name,
    //     kind,
    //     start_pos.row,
    //     start_pos.column,
    //     end_pos.row,
    //     end_pos.column,
    //     node_string
    // );

    if cursor.goto_first_child() {
        loop {
            walk_tree(cursor, source);
            let node = cursor.node();
            let start_pos = node.start_position();
            let end_pos = node.end_position();
            let kind = node.kind().trim();
            let field_id = cursor.field_id().unwrap_or(0);
            let field_name = cursor.field_name().unwrap_or("");
            let node_string = node.utf8_text(source.as_bytes()).unwrap();
            println!(
                "id: [{}], name: [{}], kind: [{}], start_pos: [{} {}] end_pos: [{} {}], node_text: [{}]",
                field_id,
                field_name,
                kind,
                start_pos.row,
                start_pos.column,
                end_pos.row,
                end_pos.column,
                node_string
            );

            if !cursor.goto_next_sibling() {
                break;
            }
        }
        cursor.goto_parent();
    }
}
