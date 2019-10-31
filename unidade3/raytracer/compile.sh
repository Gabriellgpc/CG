 
NAME=`echo $1 | sed 's/\.c//g'`
FLAGS='-lGL -lGLU -lglut -lm'

echo "Compilando " $1

g++ $1 $FLAGS -o $NAME

./$NAME
