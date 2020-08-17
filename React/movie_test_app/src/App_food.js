import React from 'react';
import PropTypes from 'prop-types';

// Component는 Upper Case로 
function Food({ name, picture, rating }) {
  return (
    <div>
      <h2>I like {name} </h2>
      <h4>{rating}/5.0</h4>
      <img src={picture} alt={name} />
    </div>
  );
}

//DB에서 넘어왔다고 가정
const foodILike = [
  {
    id: 1,
    name: 'Kimchi',
    image: 'http://aeriskitchen.com/wp-content/uploads/2008/09/kimchi_bokkeumbap_02-.jpg',
    rating: 5,
  },
];

// 일반 함수 (Lower case)
//function renderFood(dish) {
//  return <Food name={dish.name} image={dish.image} />;
//}

// 화살표 함수
//const renderFood = dish =>
//  <Food name={dish.name} image={dish.image} />;

function App() {
  return (
    <div>
      {foodILike.map(dish => (
        <Food key={dish.id} name={dish.name} picture={dish.image} rating={dish.rating} />
      ))}
    </div>
  );
}

// 모든 props는 문자열이고 반드시 있어야된다는 조건
Food.propTypes = {
  name: PropTypes.string.isRequired,
  picture: PropTypes.string.isRequired,
  rating: PropTypes.number,
};

export default App;
