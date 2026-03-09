/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {

    // call immediately
    fn(...args);

    // repeat every t ms
    const timer = setInterval(() => {
        fn(...args);
    }, t);

    // cancel function
    return function() {
        clearInterval(timer);
    };
};