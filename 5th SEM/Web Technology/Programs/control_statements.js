function percent(subject) {
  var obtained = 0;
  subject.forEach((item) => {
    obtained = obtained + Number(item);
  });
  per = obtained / 5;
  return per;
}
console.log("Percentage calculation and grade calculation program");

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
var per = 0;
var grade = "";
rl.question("enter marks for 5 subjects? ", (subject) => {
  console.log(percent(subject.split(" ")) + "%");
  per = percent(subject.split(" "));
  rl.close();
  if (per >= 90) {
    console.log("A+");
    grade = "A+";
  } else if (per < 90 && per >= 80) {
    console.log("A");
    grade = "A";
  } else if (per < 80 && per >= 70) {
    console.log("B+");
    grade = "B+";
  } else if (per < 70 && per >= 60) {
    console.log("B");
    grade = "B";
  } else if (per < 60 && per >= 50) {
    console.log("C+");
    grade = "C+";
  } else if (per < 50 && per >= 40) {
    console.log("C");
    grade = "C";
  } else {
    console.log("F");
    grade = "F";
  }

  console.log("Remarks program");
  switch (grade) {
    case "A+":
      console.log("Excelent");
      break;
    case "A":
      console.log("Great");
      break;
    case "B+":
      console.log("Very Good");
      break;
    case "B":
      console.log("Good");
      break;
    case "C+":
      console.log("Satisfactory");
      break;
    case "C":
      console.log("Acceptable");
    default:
      console.log("Dissapointment");
      break;
  }
  console.log("odd or even program");
  var num = 14;
  if (num % 2 === 0) {
    console.log("even");
  } else {
    console.log("odd");
  }
});
