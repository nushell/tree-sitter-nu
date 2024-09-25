=====
raw-strings-001-simple
=====

r#'string'#

-----

(nu_script
  (pipeline
    (pipe_element
      (val_string
          (raw_string_begin)
          (raw_string_content)
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
          (raw_string_content)
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
          (raw_string_content)
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
          (raw_string_content)
          (raw_string_end)))))
