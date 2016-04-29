
(() => {
	'use strict';

    window.permutations = permutations;

	function permutations(...array) {
		var length = array.length;
		if (length) {
			 let result = [];
			 for (let i = 0; i != length; ++i) {
					for (let sub of permutations(...except(array, i))) {
						result.push([array[i], ...sub]);
					}
			 }
			 return result;
		}
		return [[]];
	}

	function * except(array, index) {
		var length = array.length;
		for (let i = 0; i != length; ++i) {
			 if (index !== i) {
					yield array[i];
			 }
		}
	}

})();
