echo "Hello world"
echo "Enter two numbers"
read a b
echo "Enter choice"
echo "1. Add"
echo "2. Subtract"
echo "3. Multiply"
echo "4. Divide"
read choice
if [ $choice -eq 1 ];
then
	c=`expr $a + $b`
	echo "Addition= $c"
elif [ $choice -eq 2 ];
then
	c=`expr $a - $b`
	echo "Subtraction= $c"
elif [ $choice -eq 3 ];
then
	c=`expr $a \* $b`
	echo "Multipication= $c"
elif [ $choice -eq 4 ];
then
	c=`expr $a / $b`
	echo "Division= $c"
fi
