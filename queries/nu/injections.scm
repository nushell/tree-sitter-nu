((comment) @injection.content
 (#set! injection.language "comment"))

((command
 head: ((cmd_identifier) @_cmd (#any-of? @_cmd
  "find"
  "parse"
  "split"
  "str"
  " find"
  " parse"
  " split"
  " str"
 ))
 flag: [
  (short_flag name: (_) @_sflag (#eq? @_sflag "r"))
  (long_flag name: (_) @_lflag (#eq? @_lflag "regex"))
 ]
 .
 arg: (_ (string_content) @injection.content)
 (#set! injection.language "regex")
))

((_
 opr: ["=~" "!~" "like" "not-like"]
 rhs: (_ (string_content) @injection.content)
 (#set! injection.language "regex")
))

((command
 head: (_) @_cmd (#any-of? @_cmd "nu" "$nu.current-exe")
 flag: [
  (short_flag name: (_) @_sflag (#any-of? @_sflag "c" "e"))
  (long_flag name: (_) @_lflag (#any-of? @_lflag "commands" "execute"))
 ]
 .
 arg: (_ (string_content) @injection.content)
 (#set! injection.language "nu")
))
