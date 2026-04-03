function binarySearch(arr, item) {
  left = 0;
  right = arr.length - 1;

  while (left <= right) {
    mid = Math.trunc((left + right) / 2);
    if (item === arr[mid]) {
      return true;
    } else if (item < arr[mid]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return false;
}

class HashMap {
  constructor(loadFactor, capacity) {
    this.loadFactor = loadFactor;
    this.capacity = capacity;
    this.data = [];
  }

  hash(key) {
    let hashCode = 0;

    const primeNumber = 31;

    for (let i = 0; i < key.length; i++) {
      hashCode = primeNumber * hashCode + key.charCodeAt(i);
    }

    return hashCode;
  }

  set(key, value) {
    const index = this.hash(key);
    data[index] = value;
  }

  get(key) {
    const index = this.hash(key);
    if (data[index]) return data[index];
    else return null;
  }

  has(key) {
    const index = this.hash(key);
    const indexArray = [...Array(this.data.length).keys()];
    return binarySearch(indexArray, index);
  }
}
