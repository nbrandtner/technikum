//Starting point for JQuery init
$(document).ready(function () {
	$("#searchResult").hide();

	$("#btn_Search").click(function (e) {
		loaddata($("#seachfield").val());
	});

	$("#btn_Search_Funfact").click(function (e) {
		loadDataByFunFact($("#funfactField").val());
	});
});

function loaddata(searchterm) {
	$.ajax({
		type: "GET",
		url: "../serviceHandler.php",
		cache: false,
		data: { method: "queryPersonByName", param: searchterm },
		dataType: "json",
		success: function (response) {
			$("#noOfentries").val(response.length);
			$("#searchResult").empty();

			$.each(response, function (index, personArray) {
				var person = personArray[0];
				$("#searchResult").append(
					"<p>" + index + " Name: " + person.firstname + ", Email: " + person.email + ", Funfacts: " + person.funfact + "</p>"
				);
			});

			$("#searchResult").show(1000).delay(3000).hide(1000);
		},
	});
}

function loadDataByFunFact(searchterm) {
	$.ajax({
		type: "GET",
		url: "../serviceHandler.php",
		cache: false,
		data: { method: "queryPersonByFunfact", param: searchterm },
		dataType: "json",
		success: function (response) {
			$("#noOfentries").val(response.length);
			$("#searchResult").empty();

			$.each(response, function (index, personArray) {
				var person = personArray[0];
				$("#searchResult").append(
					"<p>" + index + " Name: " + person.firstname + ", Email: " + person.email + ", Funfacts: " + person.funfact + "</p>"
				);
			});

			$("#searchResult").show(1000).delay(3000).hide(1000);
		},
	});
}