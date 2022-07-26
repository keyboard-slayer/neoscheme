<h1 align="center">Neoscheme </h1>
<p align="center">Scheme with a modern touch</p>
<br />
<p align="center">
    <a href="https://github.com/keyboard-slayer/neoscheme/blob/main/LICENSE">
        <img src="https://img.shields.io/github/license/keyboard-slayer/neoscheme?style=for-the-badge"/>
    </a>
    &nbsp;
    <a href="https://github.com/keyboard-slayer/neoscheme/issues">
             <img src="https://img.shields.io/github/issues/keyboard-slayer/neoscheme?style=for-the-badge"/>
    </a>
    &nbsp;
    <a href=https://github.com/keyboard-slayer/neoscheme/pulls>
       <img src="https://img.shields.io/github/issues-pr/keyboard-slayer/neoscheme?style=for-the-badge"/>
    </a>
    &nbsp;
</p>
<br />
<br />

Neoscheme is a programming language derived from the [R6RS](https://r6rs.org) specification of the language Scheme, which is a dialect of LISP.

## Details

Neoscheme is currently interpreted, that might change in the future though.

## Examples

Here is a simple hello world program written in neoscheme:
```scheme
(display "Hello world")
```

# Roadmap

<details>
<summary> Builtins</summary>

- [X] define(variables only)
- [X] display
- [X] +
- [X] -
- [X] *
- [X] /
- [X] load 
- [ ] import
- [X] error
- [ ] let
- [ ] eval
- [X] exit
- [ ] apply
- [X] print & newline
- [ ] typechecking (boolean? integer? list? number?, etc)
- [ ] list
    - [ ] car, cdr, cons
    - [ ] length
    - [ ] map
    - [ ] filter
    - [ ] reduce
    - [ ] append
- [ ] lambda
- [ ] abs
- [ ] modulo
- [ ] quotient
- [ ] remainder
    
</details>
<details>
<summary> Standard library</summary>
<p>

- [ ] extended maths
- [ ] extended IO  
- [ ] string manipulation  
- [ ] data structures  
    
    
</p>
</details>

## License
<a href="https://opensource.org/licenses/MIT">
  <img align="right" height="96" alt="MIT License" src="https://images-wixmp-ed30a86b8c4ca887773594c2.wixmp.com/i/7195e121-eded-45cf-9aab-909deebd81b2/d9ur2lg-28410b47-58fd-4a48-9b67-49c0f56c68ce.png" />
</a>

Neoscheme is licensed under the **MIT License**.

The full text of the license can be accessed via [this link](https://opensource.org/licenses/MIT) and is also included in the [license](LICENSE) file of this software package.
