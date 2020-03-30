# Ray Tracer Challenge

Due to the COVID-19 epidemic, my class is now online and many of my students do
not have access to a graphics card.  As such, I am now chaining the remainder of
my course for focus on ray tracing.

The Pragmatic Bookshelf has an interesting looking book [The Ray Tracer
Challenge](https://pragprog.com/book/jbtracer/the-ray-tracer-challenge).  It
takes a BDD approach to building a ray tracer.  Since many of my students have
seen TDD and BDD in their software engineering courses but, seem to be
struggling with integrating these ideas into their workflow, I thought that this
book would be a good opportunity for them to see it in action.

So, let's see how this goes!

## Project organization

- deps: project dependencies.  I am going to try to use header files only
  libraries to simplify project management.
- rt-code: code distributed with the book.  Our goal is to make these into
  actual code.
- tests: test files.  Any file named `*_test.cpp` will be added to the test
  suite.
