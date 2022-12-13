// todo: move this to a better place
// ugly hack for crossOriginIsolated not enabled and SharedArrayBuffer not available
if(typeof(window)=='object' && (typeof(crossOriginIsolated)=='undefined'||!crossOriginIsolated))SharedArrayBuffer = ArrayBuffer;