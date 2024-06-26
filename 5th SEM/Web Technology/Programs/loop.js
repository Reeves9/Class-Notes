var colors = ["red", "green", "blue", "Yellow", "cyan", "magenta", "black"]; //creating an array
// using for loop
for (i = 0; i < colors.length; i++) {
  console.log(colors[i]);
}
//using do...while loop
i = 0;
do {
  console.log(colors[i]);
  i++;
} while (i < colors.length);
//using while loop
i = 0;
while (i < colors.length) {
  console.log(colors[i]);
  i++;
}
//using forEach loop
colors.forEach((item) => {
  console.log(item);
});
//using map loop
colors.map((item) => {
  console.log(item);
});
