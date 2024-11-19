=====
try-001-smoke-test
=====

try {} catch {}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_try
        (block)
        (block)))))

=====
try-002-parenthesized
=====

(
  try # comment

  {}
 # comment
  catch # comment

  {
 # comment
  }

)

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (ctrl_try
              (comment)
              (block)
              (comment)
              (comment)
              (block
                (comment)))))))))
