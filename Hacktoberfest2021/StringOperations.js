const string1 = "A string primitive";
const string2 = " B string primitive";

string1.concat(string2) // A string primitive B string primitive

string1.charAt(1) // returns "A"

string1.includes("A") // true

string1.indexOf("A") // 0;

string1.indexOf("j") // -1;

string2.replace("B", "A"); // A string primitive (note: in string2)

string1.trim(); //Trims whitespace from the beginning and end of the string

string1[0] // returns "A"

string1.length // 18

let str = "Apple, Banana, Kiwi";

str.slice(7, 13)     // Returns Banana

let text = "HELLO WORLD";

text.charCodeAt(0) // returns 72

text.split(",")          // Split on commas
text.split(" ")          // Split on spaces
text.split("|")          // Split on pipe
text.split("")           // Split in characters

let a = 'a'
let b = 'b'
if (a < b) { // true
  console.log(a + ' is less than ' + b)
} else if (a > b) {
  console.log(a + ' is greater than ' + b)
} else {
  console.log(a + ' and ' + b + ' are equal.')
}


// String primitve and string Object

let s_prim = 'foo'
let s_obj = new String(s_prim)

console.log(typeof s_prim) // Logs "string"
console.log(typeof s_obj)  // Logs "object"


let s1 = '2 + 2'              // creates a string primitive
let s2 = new String('2 + 2')  // creates a String object
console.log(eval(s1))         // returns the number 4
console.log(eval(s2))         // returns the string "2 + 2"


// Long literal String

// Methode-1
let longString = "This is a very long string which needs " +
                 "to wrap across multiple lines because " +
                 "otherwise my code is unreadable."

// Methode-2
let longString = "This is a very long string which needs \
to wrap across multiple lines because \
otherwise my code is unreadable."

// Methode-3

let longString = `This is a very long string which needs
to wrap across multiple lines because
otherwise my code is unreadable.`

