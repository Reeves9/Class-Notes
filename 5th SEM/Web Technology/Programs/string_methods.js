var text = "   I am currently involved in BSc. CSIT 5th semester.   "
//printting text
console.log(text) 
//printing lenght of string 
console.log(text.length)
//printing charecter at 5th position
console.log(text.charAt(5))
//printing charecter at 6th position
console.log(text.at(6))
//printing string at 7th position
console.log(text[7])
//printing string from 5 to 7
console.log(text.slice(5,7))
//printing string form 4 to 8
console.log(text.substring(4,8)) 
//printing to uppercase  
console.log(text.toUpperCase())
//printing to lowercase 
console.log(text.toLowerCase())
//joining two strings
console.log(text.concat("and this is extra string"))
//removing spacing ffrom the start and end of the string 
console.log(text.trim())
console.log(text.trimStart())
console.log(text.trimEnd())
//adding padding to the strings 
console.log(text.padStart(80,"x"))
console.log(text.padEnd(80,"y"))
//repeating the string twice
console.log(text.repeat(2))
//replaceing text on the string 
console.log(text.replace("am","was"))
console.log(text.replaceAll(/r/g,"w" ))
//spliting text on spaces
console.log(text.split(" "))

function add(a,b){
  return a+b
}

console.log(add(2,3))
