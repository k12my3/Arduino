$.ajaxSetup({timeout:100});

var latch = false;


function testarArduino (form) {
    TextVar = myform2.inputbox.value;
	ArduinoVar = "http://" + TextVar + ":80";
	$.get( ArduinoVar, { "cm6": 7000 })	;
	{Connection: close};
}

document.onkeydown = checkKeyDown;
document.onkeyup = checkKeyUp;

function checkKeyDown(e) {

    e = e || window.event;

    if (e.keyCode == '38') {
        // up arrow
		if (latch == false) {
			TextVar = myform2.inputbox.value;
			ArduinoVar = "http://" + TextVar + ":80";
			$.get( ArduinoVar, { "cm1": 1000 })	;
			{Connection: close};
			latch = true;
		}
    }
    else if (e.keyCode == '40') {
        // down arrow
		if (latch == false) {
			TextVar = myform2.inputbox.value;
			ArduinoVar = "http://" + TextVar + ":80";
			$.get( ArduinoVar, { "cm2": 1000 })	;
			{Connection: close};
			latch = true;
		}
    }
    else if (e.keyCode == '37') {
       // left arrow
	   if (latch == false) {
			TextVar = myform2.inputbox.value;
			ArduinoVar = "http://" + TextVar + ":80";
			$.get( ArduinoVar, { "cm3": 1000 })	;
			{Connection: close};
			latch = true;
		}

	}
    else if (e.keyCode == '39') {
       // right arrow
	   if (latch == false) {
			TextVar = myform2.inputbox.value;
			ArduinoVar = "http://" + TextVar + ":80";
			$.get( ArduinoVar, { "cm4": 1000 })	;
			{Connection: close};
			latch = true;
		}
	}
}

function checkKeyUp(e) {
    e = e || window.event;

    if ((e.keyCode == '38')||(e.keyCode == '40')||(e.keyCode == '37')||(e.keyCode == '39')) {
        // up arrow
		setTimeout(doNothing, 200);
    }
}

function doNothing(){
	TextVar = myform2.inputbox.value;
		ArduinoVar = "http://" + TextVar + ":80";
		$.get( ArduinoVar, { "cm5": 1000 })	;
		{Connection: close};
		latch = false;
}
