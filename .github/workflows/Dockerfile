FROM debian:9.5-slim

LABEL "com.github.actions.name"="Hello World"
LABEL "com.github.actions.description"="Write arguments to the standard output"
LABEL "com.github.actions.icon"="mic"
LABEL "com.github.actions.color"="purple"

LABEL "repository"="http://github.com/octocat/hello-world"
LABEL "homepage"="https://github.com/anasschoukri2/DMOJs"
LABEL "maintainer"="Octocat <octocat@github.com>"

ADD Fibonacci Sequence.cpp /Fibonacci Sequence.cpp
RUN chmod +x /Fibonacci Sequence.cpp
ENTRYPOINT ["/Fibonacci Sequence.cpp"]
