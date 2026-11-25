=====
raw-strings-001-simple
=====

  r#'string'#
r#'string'#

-----

(nu_script
  (pipeline
    (pipe_element
      (val_string
        (raw_string_begin)
        (string_content)
        (raw_string_end))))
  (pipeline
    (pipe_element
      (val_string
        (raw_string_begin)
        (string_content)
        (raw_string_end)))))

=====
raw-strings-002-simple
=====

r##'raw string: r#'bla'#'##

-----

(nu_script
  (pipeline
    (pipe_element
      (val_string
        (raw_string_begin)
        (string_content)
        (raw_string_end)))))

=====
raw-strings-003-simple
=====

r#####'string'#####

-----

(nu_script
  (pipeline
    (pipe_element
      (val_string
        (raw_string_begin)
        (string_content)
        (raw_string_end)))))

=====
raw-strings-004-with-ticks-and-tags
=====

r#####'string '#'##'#####

-----

(nu_script
  (pipeline
    (pipe_element
      (val_string
        (raw_string_begin)
        (string_content)
        (raw_string_end)))))

=====
raw-strings-005-empty-string
=====

r#''#

-----

(nu_script
  (pipeline
    (pipe_element
      (val_string
        (raw_string_begin)
        (string_content)
        (raw_string_end)))))

=====
raw-strings-006-comment-inside-raw-string
=====

r#'
# it's all just a string

some other stuff
'#

-----

(nu_script
  (pipeline
    (pipe_element
      (val_string
        (raw_string_begin)
        (string_content)
        (raw_string_end)))))

=====
raw-strings-007-hash-inside-raw-string
=====

r#'a#b'#
r##'x##y'##

-----

(nu_script
  (pipeline
    (pipe_element
      (val_string
        (raw_string_begin)
        (string_content)
        (raw_string_end))))
  (pipeline
    (pipe_element
      (val_string
        (raw_string_begin)
        (string_content)
        (raw_string_end)))))

=====
raw-strings-008-quote-without-enough-hashes-inside-raw-string
=====

r##'a'#b'##
r#'it''s'#

-----

(nu_script
  (pipeline
    (pipe_element
      (val_string
        (raw_string_begin)
        (string_content)
        (raw_string_end))))
  (pipeline
    (pipe_element
      (val_string
        (raw_string_begin)
        (string_content)
        (raw_string_end)))))

=====
raw-strings-009-extra-hashes-end-at-first-closer
=====

r#'a'##
ls

-----

(nu_script
  (pipeline
    (pipe_element
      (val_string
        (raw_string_begin)
        (string_content)
        (raw_string_end))))
  (comment)
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)))))
