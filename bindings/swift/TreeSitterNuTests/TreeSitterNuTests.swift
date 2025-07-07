import XCTest
import SwiftTreeSitter
import TreeSitterNu

final class TreeSitterNuTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_nu())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Nu grammar")
    }
}
