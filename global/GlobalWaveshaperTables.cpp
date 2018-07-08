#include "Arduino.h"


/* Javascript/HTML for generating ChebyShev tables:

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
	<head>
		<script src="http://code.jquery.com/jquery-latest.min.js" type="text/javascript"></script>
		<style>
			textarea {
				width: 300px;
				height: 500px;
			}
		</style>
	</head>
	<body>
		<textarea id="chevychev-table-t3"></textarea>
		<textarea id="chevychev-table-t4"></textarea>
		<textarea id="chevychev-table-t5"></textarea>
		<textarea id="chevychev-table-t6"></textarea>
	</body>

	<script>

		$('textarea').val('');

		var table_t3 = $('#chevychev-table-t3');
		var table_t4 = $('#chevychev-table-t4');
		var table_t5 = $('#chevychev-table-t5');
		var table_t6 = $('#chevychev-table-t6');

		for(t=0; t<4096; t++)
		{
			x = (t-2048)/2048;

			// t3 = 4x^3-3x
			t3 = (4 * Math.pow(x,3)) - (3 * x);
			append_table_value(table_t3, t3);

			// t4 = 8x^4-8x^2+1
			t4 = (8 * Math.pow(x,4)) - (8 * Math.pow(x,2)) + 1;
			append_table_value(table_t4, t4);

			// t5 = 16x^5 - 20x^3 + 5x
			t5 = (16 * Math.pow(x,5)) - (20 * Math.pow(x,3)) + (5 * x);
			append_table_value(table_t5, t5);

			// t6 = 32x^6 - 48x^4 + 18x^2 - 1
			t6 = (32 * Math.pow(x,6)) - (48 * Math.pow(x,4)) + (18 * Math.pow(x, 2)) - 1;
			append_table_value(table_t6, t6);
		}

		function convert_to_12_bit(v)
		{
			return(parseInt(((v + 1) / 2) * 4095));
		}

		function append_table_value(table_element, v)
		{
			$(table_element).val($(table_element).val() + convert_to_12_bit(v) + ', ');
		}

	</script>	
</html>

*/
