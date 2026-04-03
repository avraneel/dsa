class HashMap {
  constructor(loadFactor, capacity) {
    this.loadFactor = loadFactor ?? 0.75;
    this.capacity = capacity ?? 16;
    this.data = [];
  }

  hash(key) {
    let hashCode = 0;

    const primeNumber = 31;

    for (let i = 0; i < key.length; i++) {
      hashCode = (primeNumber * hashCode + key.charCodeAt(i)) % this.capacity;
    }

    return hashCode;
  }

  set(key, value) {
    const index = this.hash(key);
    data[index] = value;
    if (index / this.capacity > this.loadFactor) {
      this.capacity *= 2;
    }
  }

  get(key) {
    const index = this.hash(key);
    if (data[index]) return data[index];
    else return null;
  }

  has(key) {
    const index = this.hash(key);
    const val = this.data[index];
    return val == undefined ? false : true;
  }

  remove(key) {
    const index = this.hash(key);
    const val = this.data[index];
    if (val != undefined) {
      // key found
      this.data[index] = undefined;
      return true;
    } else {
      return false;
    }
  }

  length() {}

  clear() {
    for (let i = 0; i < this.data.capacity; i++) {
      data[i] = undefined;
    }
  }
}
