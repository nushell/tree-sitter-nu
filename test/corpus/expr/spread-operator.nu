====
spread-001-list-literals
====

[
  ...$dogs.names,
  Polly
  ...([])
  ...[Porky Bessie]
  ...Nemo
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          entry: (val_entry
            spread: (val_variable
              name: (identifier)
              (cell_path
                (path
                  (val_string)))))
          entry: (val_entry
            item: (val_string))
          entry: (val_entry
            spread: (expr_parenthesized
              (pipeline
                (pipe_element
                  (val_list)))))
          entry: (val_entry
            spread: (val_list
              (list_body
                entry: (val_entry
                  item: (val_string))
                entry: (val_entry
                  item: (val_string)))))
          entry: (val_entry
            item: (val_string)))))))

====
spread-002-record-literals
====

{
  ...$config,
  users: [alice bob]
  ...{ url: example.com },
  ...(sys mem)
}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_record
        (record_body
          entry: (record_entry
            spread: (val_variable
              name: (identifier)))
          entry: (record_entry
            key: (identifier)
            value: (val_list
              (list_body
                entry: (val_entry
                  item: (val_string))
                entry: (val_entry
                  item: (val_string)))))
          entry: (record_entry
            spread: (val_record
              (record_body
                entry: (record_entry
                  key: (identifier)
                  value: (val_string)))))
          entry: (record_entry
            spread: (expr_parenthesized
              (pipeline
                (pipe_element
                  (command
                    head: (cmd_identifier)
                    arg_str: (val_string)))))))))))

====
spread-003-command-arguments
====

echo ...$foo ...([]) ...[1] ...foo

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        head: (cmd_identifier)
        arg_spread: (val_variable
          name: (identifier))
        arg_spread: (expr_parenthesized
          (pipeline
            (pipe_element
              (val_list))))
        arg_spread: (val_list
          (list_body
            entry: (val_entry
              item: (val_number))))
        arg_str: (val_string)))))
