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

 # comment
  finally # comment

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
                (comment))
              (comment)
              (comment)
              (block
                (comment)))))))))

=====
try-003-catch-closure
=====

try {} catch {|e|}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_try
        try_branch: (block)
        catch_branch: (val_closure
          parameters: (parameter_pipes
            (parameter
              param_name: (identifier))))))))

=====
try-004-catch-finally
=====

try {} catch {} finally {}
try {} catch {|e|} finally {|e|}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_try
        try_branch: (block)
        catch_branch: (block)
        finally_branch: (block))))
  (pipeline
    (pipe_element
      (ctrl_try
        try_branch: (block)
        catch_branch: (val_closure
          parameters: (parameter_pipes
            (parameter
              param_name: (identifier))))
        finally_branch: (val_closure
          parameters: (parameter_pipes
            (parameter
              param_name: (identifier))))))))

=====
try-005-finally
=====

try {} finally {}
try {} finally {|e|}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_try
        try_branch: (block)
        finally_branch: (block))))
  (pipeline
    (pipe_element
      (ctrl_try
        try_branch: (block)
        finally_branch: (val_closure
          parameters: (parameter_pipes
            (parameter
              param_name: (identifier))))))))
