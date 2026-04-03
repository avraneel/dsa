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
    const val = this.data[index];
    return val == false ? false : val;
  }

  remove(key) {
    const index = binarySearch();
  }
}
