<?php

function InsertionSort($array)
{
    $size = count($array); //Array Size
    //Outer Loop
    for ($i = 0; $i < $size; $i++) {
        $current_value = $array[$i];
        $previous_index = $i - 1;
        //Inner Loop
        while (
            $previous_index >= 0 &&
            $array[$previous_index] > $current_value
        ) {
            //Move the bigger value to the right & decrement the previous position.
            $array[$previous_index + 1] = $array[$previous_index];
            $previous_index--;
        }
        //Assign the $current_value to the last index that was successfully moved.
        $array[$previous_index + 1] = $current_value;
    }
    //Return the sorted array
    return $array;
}

$array = [5, 3, 1, 7, 6, 10, 8, 20, 15];

echo "The Initial array of numbers is " . implode(",", $array) . "\n";
shuffle($array);
echo "The Shuffled array of numbers is " . implode(",", $array) . "\n";
echo "The Sorted array of numbers is " . implode(",", InsertionSort($array));
